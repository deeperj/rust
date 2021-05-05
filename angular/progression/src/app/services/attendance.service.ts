import { Injectable } from '@angular/core';
import { Observable, throwError } from 'rxjs';
import { catchError, retry } from 'rxjs/operators';
import { HttpClient, HttpHeaders, HttpErrorResponse } from '@angular/common/http';
import { GroupModule } from '../models/GroupModule';
import { Attendance } from '../models/ui/Attendance';
import { Student } from '../models/Student';

@Injectable({
  providedIn: 'root'
})
export class AttendanceService {
  private attendanceUrl = 'https://localhost:5001/api/Facade/GetGroupModules';
  private httpOptions = {
      headers: new HttpHeaders( { 'Content-Type': 'application/json' })
  };

  constructor(
    private httpClient : HttpClient) { }

  private httpErrorHandler (error: HttpErrorResponse) {
    if (error.error instanceof ErrorEvent) {
        console.error("A client side error occurs. The error message is " + error.message);
        } else {
          console.error(
              "An error happened in server. The HTTP status code is "  + error.status + " and the error returned is " + error.message);
        }
  
    return throwError("Error occurred. Pleas try again");
  }

  getAttendanceStudents() : Observable<GroupModule[]> {
    return this.httpClient.get<GroupModule[]>(this.attendanceUrl, this.httpOptions)
    .pipe(retry(3),catchError(this.httpErrorHandler));
  }

  progressionBinder(att:Attendance[], modid:number ,idx:number){
    return att.find(a=>{return a.groupModuleId===modid})?.students[idx];
  }

}