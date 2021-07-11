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
    this.rootsvc.pivotReady.subscribe(data=>{
      let len:number=0;
      this.rootsvc.progress.subscribe(d=>len=d.length);
      if(data==len-1){
        this.rootsvc.dbg.info("Items loaded");
      }
    });
  }

}
