import { Injectable } from '@angular/core';
import { Observable, throwError } from 'rxjs';
import { catchError, retry } from 'rxjs/operators';
import { HttpClient, HttpHeaders, HttpErrorResponse } from '@angular/common/http';
import { GroupModule } from '../models/GroupModule';
import { Attendance } from '../models/ui/Attendance';
import { Student } from '../models/Student';
import { DebugService } from './debug.service';
import { Progression } from '../models/Progression';
import { NewStudent } from '../models/ui/NewStudent';
import {Subject} from 'rxjs';
import { Rpag } from '../models/enums';

@Injectable({
  providedIn: 'root'
})
export class AttendanceService {
  private attendanceUrl = 'https://localhost:5001/api/Facade/GetGroupModules';
  private addAttendanceUrl = 'https://localhost:5001/api/Facade/SaveAttendance';
  private addStudentsUrl = 'https://localhost:5001/api/Facade/UploadStudents';
  private attendanceDatesUrl = 'https://localhost:5001/api/Facade/GetUniqueAttendanceDates';
  private studAttendanceByDateUrl = 'https://localhost:5001/api/Facade/StudAttendanceByDate';
  private attendanceScoreByModuleUrl = 'https://localhost:5001/api/Facade/StudAttendanceScoreByModule';
  private httpOptions = {
      headers: new HttpHeaders( { 'Content-Type': 'application/json' })
  };
  _attendance: Attendance[]=[];
  pivotReady = new Subject();

  constructor(
    private httpClient : HttpClient,
    private dbg : DebugService,
    ) { }

    public get attendance() {
      return this._attendance;
  }

  public set attendance(gmds: Attendance[]) {
      if (this._attendance.length==0) {
          this._attendance=gmds;
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

  getStudAttendanceByDate(sid: number, param:string) : Observable<Progression> {
    const finalUrl = this.studAttendanceByDateUrl + "/" + sid + "/" + encodeURIComponent(param);
    // const finalUrl = this.studAttendanceByDateUrl + "?id=" + sid + "&param=" + param;
    return this.httpClient.get<Progression>(finalUrl, this.httpOptions)
    .pipe(
       retry(1),
       catchError(this.httpErrorHandler)
    );
  }

  getStudAttendanceScoreByModule(sid: number, modid:number) : Observable<number> {
    const finalUrl = this.attendanceScoreByModuleUrl + "/" + sid + "/" + modid;
    // console.log(finalUrl);
    return this.httpClient.get<number>(finalUrl, this.httpOptions)
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

  addAttendance(attendance: Progression[]): Observable<any> {
    return this.httpClient.post<any>(this.addAttendanceUrl,  attendance, this.httpOptions)
    .pipe(
       retry(3),
       catchError(this.httpErrorHandler)
    );
  }

  uploadStudents(newStudents: NewStudent[]): Observable<any> {
    return this.httpClient.post<any>(this.addStudentsUrl,  newStudents, this.httpOptions)
    .pipe(
       retry(3),
       catchError(this.httpErrorHandler)
    );
  }


  studName(stud:Student|null|undefined):string{
    return stud?stud.lastName.concat(' '+stud.otherNames):"";
  }

  getRpag(score:number):Rpag{
      if(score>=70)
        return Rpag.G;
      else if(score <70 && score >=50)
        return Rpag.A;
      else if(score <50 && score >=40)
        return Rpag.P;
      else
        return Rpag.R;
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