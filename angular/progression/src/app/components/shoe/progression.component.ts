import { Component, OnInit } from '@angular/core';
import { GroupModule } from 'src/app/models/GroupModule';
import { AttendanceService } from '../../services/attendance.service';
import { DebugService } from '../../services/debug.service';

@Component({
  selector: 'app-progression',
  templateUrl: './progression.component.html',
  styleUrls: ['./progression.component.css']
})
export class ProgressionComponent implements OnInit {
  typesOfShoes: string[] = ['Boots', 'Clogs', 'Loafers', 'Moccasins', 'Sneakers'];
  attendance!: GroupModule[];
  constructor(private debugService: DebugService, private restService : AttendanceService) { }

  ngOnInit(): void {
    this.getAttendance();
  }
  getAttendance() {
    //throw new Error('Method not implemented.');
    this.restService.getAttendanceStudents()
    .subscribe( data => this.attendance = data );
}

}
