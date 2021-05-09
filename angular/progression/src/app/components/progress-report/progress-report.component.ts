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

  constructor( 
    private dbg: DebugService, 
    public rootsvc : AttendanceService) 
    { 
    }

  ngOnInit(): void {
  }

}
