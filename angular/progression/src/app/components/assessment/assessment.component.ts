import { Component, OnInit } from '@angular/core';
import { AttendanceService } from 'src/app/services/attendance.service';
import { DebugService } from 'src/app/services/debug.service';

@Component({
  selector: 'app-assessment',
  templateUrl: './assessment.component.html',
  styleUrls: ['./assessment.component.css']
})
export class AssessmentComponent implements OnInit {

  constructor( 
    private dbg: DebugService, 
    public rootsvc : AttendanceService) 
    { 
    }

  ngOnInit(): void {
  }

}
