import { Component, OnInit, Input, EventEmitter, Output } from '@angular/core';
import * as moment from 'moment';
import { GroupModule } from 'src/app/models/GroupModule';
import { AttendanceReport } from 'src/app/models/ui/Attendance';
import { AttendanceService } from 'src/app/services/attendance.service';
import { DebugService } from 'src/app/services/debug.service';

@Component({
  selector: 'app-attendance-report',
  templateUrl: './attendance-report.component.html',
  styleUrls: ['./attendance-report.component.css']
})
export class AttendanceReportComponent implements OnInit {
  @Input() attRep!: number;
  @Input() theDates: string[] = [];
  @Input() displayedColumns: string[] = ['SN','StudentID','LastName','OtherNames',...['hello','world']];
  toggle:boolean=false;
  data: any[] =[];
  constructor(
    private dbg: DebugService, 
    public rootsvc : AttendanceService
  ) { }

  ngOnInit(): void {
    if(this.displayedColumns){
      this.displayedColumns=['SN','StudentID','LastName','OtherNames',...['hello','world']];
      console.log(this.displayedColumns);//this.attRep.dates.map(c=>moment(c.toDateString()).format('MMM-DD'))];
    }
    this.data=this.getData(this.theDates);
    console.log(this.attRep);
    // setTimeout(()=>{
    // },1000);
  }
  columnsToDisplay: string[] = this.displayedColumns.slice();

  addColumn_NOT_USED() {
    console.log(this.columnsToDisplay);
    const randomColumn = Math.floor(Math.random() * this.displayedColumns.length);
    this.columnsToDisplay.push(this.displayedColumns[randomColumn]);
  }

  removeColumn_NOT_USED() {
    if (this.columnsToDisplay.length) {
      this.columnsToDisplay.pop();
    }
  }

  toggleColumn(col:string) {                             
    this.toggle=!this.toggle
    if (this.toggle) {
      this.columnsToDisplay=[col];
    }else{
      this.columnsToDisplay=this.displayedColumns.slice();
    }
  }

  shuffle_NOT_USED() {
    let currentIndex = this.columnsToDisplay.length;
    while (0 !== currentIndex) {
      let randomIndex = Math.floor(Math.random() * currentIndex);
      currentIndex -= 1;

      // Swap
      let temp = this.columnsToDisplay[currentIndex];
      this.columnsToDisplay[currentIndex] = this.columnsToDisplay[randomIndex];
      this.columnsToDisplay[randomIndex] = temp;
    }
  }

  getData(ext:string[]){
    // console.log('this.rootsvc.groupMods=');
    // console.log(this.rootsvc.groupMods);
    let el = {};
    ext.forEach(v=>{el={...el,...{[v]:'*  '}}})
    return this.rootsvc.groupMods[this.attRep].group.students.map((c,i)=>{
      let v1= ({
        SN: i+1,
        StudentID:c.uniCode,
        LastName: c.lastName,
        OtherNames: c.otherNames,
      });
      return {...v1,...el};
    });
  }
}
