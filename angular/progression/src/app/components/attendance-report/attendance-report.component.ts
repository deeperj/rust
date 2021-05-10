import { Component, OnInit, Input, EventEmitter, Output } from '@angular/core';
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
  theDates: string[] = [];
  displayedColumns: string[] = ['SN','StudentID','LastName','OtherNames','Attendance',...['hello','world']];
  columnsToDisplay!: string[]
  toggle:boolean=false;
  data: any[] =[];
  gmod!: GroupModule;
  constructor(
    private dbg: DebugService, 
    public rootsvc : AttendanceService
  ) { }

  ngOnInit(): void {
    this.gmod=this.rootsvc.groupMods[this.attRep];
    if(this.displayedColumns){
      this.uniqueAttendanceDates();
    }
  }

  addColumn_NOT_USED() {
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
  uniqueAttendanceDates()   {
    const modid=this.gmod.module.moduleID;
    const grpid=this.gmod.group.groupID;
    this.rootsvc.getAttendanceDates(modid,grpid)
    .subscribe( data => {
      this.theDates = data;
      this.displayedColumns=['SN','StudentID','LastName','OtherNames','Attendance',...this.theDates];
      this.data=this.getData(this.theDates);
      this.columnsToDisplay = this.displayedColumns.slice();
    } );
  }  


  getData(ext:string[]){
    // console.log('this.rootsvc.groupMods=');
    // console.log(this.rootsvc.groupMods);
    let el = {};
    ext.forEach(v=>{el={...el,...{[v]:'*  '}}})
    return this.gmod.group.students.map((c,i)=>{
      let v1= ({
        SN: i+1,
        StudentID:c.uniCode,
        LastName: c.lastName,
        OtherNames: c.otherNames,
        Attendance: 100,
      });
      return {...v1,...el};
    });
  }
}
