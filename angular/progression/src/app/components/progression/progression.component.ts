import { Component, OnInit } from '@angular/core';
//import { Console } from 'node:console';
import { GroupModule } from '../../models/GroupModule';
import { Progression } from '../../models/Progression';
import { AttendanceService } from '../../services/attendance.service';
import { DebugService } from '../../services/debug.service';

@Component({
  selector: 'app-progression',
  templateUrl: './progression.component.html',
  styleUrls: ['./progression.component.css']
})
export class ProgressionComponent implements OnInit {
  panelOpenState = false;
  attendance!: Progression[];
  attendanceStudents!: GroupModule[];
  constructor(private debugService: DebugService, private restService : AttendanceService) { }

  ngOnInit(): void {
    this.getAttendance();
  }
  getAttendance() {
    //throw new Error('Method not implemented.');
    this.restService.getAttendanceStudents()
    .subscribe( data => {
      console.log(data[0].group.students);
      console.log(data[0].group.students);
      this.attendanceStudents = data
    });
}

}
