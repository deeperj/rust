import { Injectable } from '@angular/core';
import { Observable, throwError } from 'rxjs';
import { catchError, retry } from 'rxjs/operators';
import { HttpClient, HttpHeaders, HttpErrorResponse, JsonpClientBackend } from '@angular/common/http';
import { GroupModule } from '../models/GroupModule';
import { ModEmailStatus, Progress, ProgressRecord } from '../models/ui/Progress';
import { Student } from '../models/Student';
import { DebugService } from './debug.service';
import { Progression } from '../models/Progression';
import { NewStudent, ProgressUpdate } from '../models/ui/NewStudent';
import {Subject} from 'rxjs';
import { Rpag, RPAGType } from '../models/enums';
import { ModuleTask } from '../models/ModuleTask';
import * as moment from 'moment';
import { ProgressionState, ProgressionStateModel } from '../store/progress.state';
import { Store, Select } from '@ngxs/store';
import produce from 'immer';


@Injectable({
  providedIn: 'root'
})
export class DomainService {
  private weeklyReminderUrl = 'https://localhost:5001/api/Facade/SendWeeklyStatus';
  private attendanceUrl = 'https://localhost:5001/api/Facade/GetGroupModules';
  private addAssessmentUrl = 'https://localhost:5001/api/Progressions';
  private addAttendanceUrl = 'https://localhost:5001/api/Facade/SaveAttendance';
  private editAttendanceUrl = 'https://localhost:5001/api/Facade/UpdateAttendance';
  private addStudentsUrl = 'https://localhost:5001/api/Facade/UploadStudents';
  private attendanceDatesUrl = 'https://localhost:5001/api/Facade/GetUniqueAttendanceDates';
  private sumTasksByModuleUrl = 'https://localhost:5001/api/Facade/SumTasksByModule';
  private summativesByGroupUrl = 'https://localhost:5001/api/Facade/SummativesByGroupModule';
  private studAttendanceByDateUrl = 'https://localhost:5001/api/Facade/StudAttendanceByDate';
  private attendanceByModuleUrl = 'https://localhost:5001/api/Facade/StudAttendanceByModule';
  protected httpOptions = {
      headers: new HttpHeaders( { 'Content-Type': 'application/json' })
  };

  @Select(ProgressionState.getProgress) 
  progress!: Observable<Progress[]>;
  
  _pivotReady = new Subject();

  constructor(
    protected httpClient : HttpClient,
    protected _dbg : DebugService,
    protected _store : Store,
    ) { 
      //this.progress = this.store.select(state => state.progress.progress);
    }

    public get dbg() {
      return this._dbg;
    }

    public get store() {
      return this._store;
    }

    // public get progress() {
    //   return this._progress;
    // }
    // public set progress(gmds: Progress[]) {
    //     if (this._progress.length==0) {
    //         this._progress=gmds;
    //     }
    // }

    public get pivotReady() {
      return this._pivotReady;
    }
    

  protected httpErrorHandler (error: HttpErrorResponse) {
    // console.log('here',this.attendanceScoreByModuleUrl)
    if (error.error instanceof ErrorEvent) {
      console.error("A client side error occurs. The error message is " + error.message);
    } else {
      console.error(
          "An error happened in server. The HTTP status code is "  + error.status + " and the error returned is " + error.message);
    }
    return throwError("Error occurred. Please try again");
  }

  sendWeeklyReminder(params:ModEmailStatus) : Observable<any> {
    return this.httpClient.post<any>(this.weeklyReminderUrl, params, this.httpOptions)
    .pipe(retry(3),catchError(this.httpErrorHandler));
  }

  getAttendanceStudents() : Observable<GroupModule[]> {
    return this.httpClient.get<GroupModule[]>(this.attendanceUrl, this.httpOptions)
    .pipe(retry(3),catchError(this.httpErrorHandler));
  }

  getStudAttendanceByDate(sid: number, param:string) : Observable<Progression> {
    const finalUrl = this.studAttendanceByDateUrl + "/" + sid + "/" + encodeURIComponent(param);
    // const finalUrl = this.studAttendanceByDateUrl + "?id=" + sid + "&param=" + param;
    return this.httpClient.get<Progression>(finalUrl, this.httpOptions)
    .pipe(
       retry(1),
       catchError(this.httpErrorHandler)
    );
  }

  getSummativesByGroup(modid: number, grpid:number, rpag:RPAGType) : Observable<Progression[]> {
    const finalUrl = this.summativesByGroupUrl + "/" + modid + "/" + grpid + "/" + rpag;
    return this.httpClient.get<Progression[]>(finalUrl, this.httpOptions)
    .pipe(
       retry(1),
       catchError(this.httpErrorHandler)
    );
  }

  getSumTasksByModule(modid: number, rpag:RPAGType) : Observable<ModuleTask[]> {
    const finalUrl = this.sumTasksByModuleUrl + "/" + modid + "/" + rpag;
    return this.httpClient.get<ModuleTask[]>(finalUrl, this.httpOptions)
    .pipe(
       retry(1),
       catchError(this.httpErrorHandler)
    );
  }

  getStudAttendanceByModule(sid: number, modid:number) : Observable<Progression[]> {
    const finalUrl = this.attendanceByModuleUrl + "/" + sid + "/" + modid;
    // console.log(finalUrl);
    return this.httpClient.get<Progression[]>(finalUrl, this.httpOptions)
    .pipe(
       retry(1),
       catchError(this.httpErrorHandler)
    );
  }

  getAttendanceDates(modid: number, grpid:number) : Observable<string[]> {
    const finalUrl = this.attendanceDatesUrl + "/" + modid + "/" + grpid;
    return this.httpClient.get<string[]>(finalUrl, this.httpOptions)
    .pipe(
       retry(1),
       catchError(this.httpErrorHandler)
    );
  }

  editAttendance(attendance: Progression[]): Observable<any> {
    return this.httpClient.post<any>(this.editAttendanceUrl,  attendance, this.httpOptions)
    .pipe(
       retry(3),
       catchError(this.httpErrorHandler)
    );
  }

  editAssessment(id:number, assessment: Progression): Observable<any> {
    console.log(JSON.stringify(assessment));
    const finalUrl = this.addAssessmentUrl+'/'+id;
    console.log(finalUrl);
    return this.httpClient.put<any>(finalUrl,  assessment, this.httpOptions)
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

  refresh(){
    window.location.reload();
  }

  addAssessment(assessment: Progression): Observable<any> {
    return this.httpClient.post<any>(this.addAssessmentUrl,  assessment, this.httpOptions)
    .pipe(
       retry(3),
       catchError(this.httpErrorHandler)
    );
  }

  uploadStudents(newStudents: NewStudent[]): Observable<any> {
    // console.log(JSON.stringify(newStudents));
    return this.httpClient.post<any>(this.addStudentsUrl,  newStudents, this.httpOptions)
    .pipe(
       retry(3),
       catchError(this.httpErrorHandler)
    );
  }

  studName(stud:Student|null|undefined):string{
    return stud?stud.lastName.concat(' '+stud.otherNames):"";
  }
  rpag(rpag:Rpag|null){
    //console.log(rpag);
    switch(rpag){
      case Rpag.R:
        return "red";
      case Rpag.P:
        return "pink";
      case Rpag.A:
        return "yellow";
      case Rpag.G:
        return "green";
      default:
        return "black";
    }
  }
  studentLog(student:(Progression & ProgressRecord)):string{
    //console.log(JSON.stringify(student.attendance));
    let aLog:string[]=student.attendance.filter(c=>c.comments?c.comments.trim().length>0:false)
                          .map(c=>moment(c.dueDate).format("dd DD-MMM-yyyy")+c.comments);
    return aLog.join(" \n");
  }
  
  // ref: http://stackoverflow.com/a/1293163/2343
  // This will parse a delimited string into an array of
  // arrays. The default delimiter is the comma, but this
  // can be overriden in the second argument.
  CSVToArray( strData:string, strDelimiter:string=',' ){
    // Check to see if the delimiter is defined. If not,
    // then default to comma.
    strDelimiter = (strDelimiter || ",");

    // Create a regular expression to parse the CSV values.
    var objPattern = new RegExp(
        (
            // Delimiters.
            "(\\" + strDelimiter + "|\\r?\\n|\\r|^)" +

            // Quoted fields.
            "(?:\"([^\"]*(?:\"\"[^\"]*)*)\"|" +

            // Standard fields.
            "([^\"\\" + strDelimiter + "\\r\\n]*))"
        ),
        "gi"
        );


    // Create an array to hold our data. Give the array
    // a default empty first row.
    var arrData:string[][] = [[]];

    // Create an array to hold our individual pattern
    // matching groups.
    var arrMatches = null;


    // Keep looping over the regular expression matches
    // until we can no longer find a match.
    while (arrMatches = objPattern.exec( strData )){

        // Get the delimiter that was found.
        var strMatchedDelimiter = arrMatches[ 1 ];

        // Check to see if the given delimiter has a length
        // (is not the start of string) and if it matches
        // field delimiter. If id does not, then we know
        // that this delimiter is a row delimiter.
        if (
            strMatchedDelimiter.length &&
            strMatchedDelimiter !== strDelimiter
            ){

            // Since we have reached a new row of data,
            // add an empty row to our data array.
            arrData.push( [] );

        }

        var strMatchedValue;

        // Now that we have our delimiter out of the way,
        // let's check to see which kind of value we
        // captured (quoted or unquoted).
        if (arrMatches[ 2 ]){

            // We found a quoted value. When we capture
            // this value, unescape any double quotes.
            strMatchedValue = arrMatches[ 2 ].replace(
                new RegExp( "\"\"", "g" ),
                "\""
                );

        } else {

            // We found a non-quoted value.
            strMatchedValue = arrMatches[ 3 ];

        }


        // Now that we have our value string, let's add
        // it to the data array.
        arrData[ arrData.length - 1 ].push( strMatchedValue );
    }

    // Return the parsed data.
    return( arrData );
  }

}