import { Component, OnInit } from '@angular/core';
import { DomainService } from 'src/app/services/domain.service';

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
    this.rootsvc.pivotReady.subscribe(data=>{
      if(data==this.rootsvc.progress.length-1){
        this.rootsvc.dbg.info("Items loaded");
      }
    });
  }

}
