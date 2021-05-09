import { Component, OnInit } from '@angular/core';
import { GroupModule } from 'src/app/models/GroupModule';
import { AttendanceService } from 'src/app/services/attendance.service';
import { DebugService } from 'src/app/services/debug.service';

@Component({
  selector: 'app-progress-report',
  templateUrl: './progress-report.component.html',
  styleUrls: ['./progress-report.component.css']
})
export class ProgressReportComponent implements OnInit {
  dates!: string[];
  cols!: string[];

  constructor( 
    private dbg: DebugService, 
    public rootsvc : AttendanceService) 
    { 
    }

  ngOnInit(): void {
  }

  uniqueAttendanceDates(gmod:GroupModule)   {
    const modid=gmod.module.moduleId;
    const grpid=gmod.group.groupId;
    console.log('here',modid,grpid);
    console.dir(gmod);
    this.rootsvc.getAttendanceDates(modid,grpid)
    .subscribe( data => this.dates = data );
    this.cols=['SN','StudentID','LastName','OtherNames',...this.dates];
    return this.dates;
  }  

}
