import { Injectable } from '@angular/core';
import { Observable, throwError } from 'rxjs';
import { catchError, retry } from 'rxjs/operators';
import { HttpClient } from '@angular/common/http';
import { DebugService } from './debug.service';
import { Progression } from '../models/Progression';
import { AttendanceService } from './attendance.service';

@Injectable({
  providedIn: 'root'
})
export class AssessmentService extends AttendanceService {
  private summativesUrl = 'https://localhost:5001/api/Facade/Summatives';
  private summativesByModuleUrl = 'https://localhost:5001/api/Facade/SummativesByGroupModule';

  constructor(httpClient : HttpClient, dbg : DebugService,
    ) { 
      super(httpClient,dbg);
    }

  getSummativesNOT_USED(sid: number, modid:number) : Observable<Progression[]> {
    const finalUrl = this.summativesUrl + "/" + sid + "/" + modid;
    // console.log(finalUrl);
    return this.httpClient.get<Progression[]>(finalUrl, this.httpOptions)
    .pipe(
       retry(1),
       catchError(this.httpErrorHandler)
    );
  }

  getSummativesByModule(modid: number, grpid:number) : Observable<Progression[]> {
    const finalUrl = this.summativesByModuleUrl + "/" + modid + "/" + grpid;
    return this.httpClient.get<Progression[]>(finalUrl, this.httpOptions)
    .pipe(
       retry(1),
       catchError(this.httpErrorHandler)
    );
  }

  editAttendanceNOT_USED(attendance: Progression[]): Observable<any> {
    return this.httpClient.post<any>(this.summativesUrl,  attendance, this.httpOptions)
    .pipe(
       retry(3),
       catchError(this.httpErrorHandler)
    );
  }

  addAttendanceNOT_USED(attendance: Progression[]): Observable<any> {
    return this.httpClient.post<any>(this.summativesUrl,  attendance, this.httpOptions)
    .pipe(
       retry(3),
       catchError(this.httpErrorHandler)
    );
  }

}