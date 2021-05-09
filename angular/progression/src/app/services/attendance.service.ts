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
  private attendanceDatesUrl = 'https://localhost:5001/api/Facade/GetUniqueAttendanceDates';
  private httpOptions = {
      headers: new HttpHeaders( { 'Content-Type': 'application/json' })
  };
  _groupMods: GroupModule[]=[];

  constructor(
    private httpClient : HttpClient,
    private dbg : DebugService,
    ) { }

    public get groupMods() {
      return this._groupMods;
  }

  public set groupMods(gmds: GroupModule[]) {
      if (this._groupMods.length==0) {
          this._groupMods=gmds;
      }
  }

  private httpErrorHandler (error: HttpErrorResponse) {
    console.log('err_handler: '+this.dbg);
    if (error.error instanceof ErrorEvent) {
      console.error("A client side error occurs. The error message is " + error.message);
    } else {
      console.error(
          "An error happened in server. The HTTP status code is "  + error.status + " and the error returned is " + error.message);
    }
    this.dbg.info('Error '+error.status + ': '+ error.message);
    return throwError("Error occurred. Please try again");
  }

  getAttendanceStudents() : Observable<GroupModule[]> {
    return this.httpClient.get<GroupModule[]>(this.attendanceUrl, this.httpOptions)
    .pipe(retry(3),catchError(this.httpErrorHandler));
  }

  getAttendanceDates(modid: number, grpid:number) : Observable<string[]> {
    return this.httpClient.get<string[]>(this.attendanceDatesUrl + "/" + modid + "/" + grpid, this.httpOptions)
    .pipe(
       retry(3),
       catchError(this.httpErrorHandler)
    );
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