import { Injectable } from '@angular/core';
import { Observable, throwError } from 'rxjs';
import { catchError, retry } from 'rxjs/operators';
import { HttpClient, HttpHeaders, HttpErrorResponse } from '@angular/common/http';
import { GroupModule } from '../models/GroupModule';
import { Attendance } from '../models/ui/Attendance';
import { Student } from '../models/Student';
import { DebugService } from './debug.service';
import { Progression } from '../models/Progression';

@Injectable({
  providedIn: 'root'
})
export class AttendanceService {
  private attendanceUrl = 'https://localhost:5001/api/Facade/GetGroupModules';
  private addAttendanceUrl = 'https://localhost:5001/api/Facade/SaveAttendance';
  private httpOptions = {
      headers: new HttpHeaders( { 'Content-Type': 'application/json' })
  };

  constructor(
    private httpClient : HttpClient,
    private dbg : DebugService,
    ) { }

  private httpErrorHandler (error: HttpErrorResponse) {
    if (error.error instanceof ErrorEvent) {
      console.error("A client side error occurs. The error message is " + error.message);
    } else {
      console.error(
          "An error happened in server. The HTTP status code is "  + error.status + " and the error returned is " + error.message);
    }
    console.log('here '+this.dbg);
    this.dbg.info('Error '+error.status + ': '+ error.message);
    return throwError("Error occurred. Please try again");
  }

  getAttendanceStudents() : Observable<GroupModule[]> {
    return this.httpClient.get<GroupModule[]>(this.attendanceUrl, this.httpOptions)
    .pipe(retry(3),catchError(this.httpErrorHandler));
  }

  addAttendance(attendance: Progression[]): Observable<any> {
    return this.httpClient.post<any>(this.addAttendanceUrl,  attendance, this.httpOptions)
    .pipe(
       retry(3),
       catchError(this.httpErrorHandler)
    );
  }

  progressionBinder_NOT_USED(att:Attendance[], modid:number ,idx:number){
    return att.find(a=>{ a.groupModuleId===modid})?.students[idx];
  }

  studName(stud:Student|null|undefined):string{
    return stud?stud.lastName.concat(' '+stud.otherNames):"";
  }

}