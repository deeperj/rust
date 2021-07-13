import { Component, OnInit } from '@angular/core';
import { DomainService } from 'src/app/services/domain.service';
import { toArray } from 'rxjs/operators';

@Component({
  selector: 'app-progress-report',
  templateUrl: './progress-report.component.html',
  styleUrls: ['./progress-report.component.css']
})
export class ProgressReportComponent implements OnInit {

  constructor( 
    public rootsvc : DomainService) 
    { 
    }

  ngOnInit(): void {
  }

}
