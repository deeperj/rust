import { Component, OnInit } from '@angular/core';
import { DomainService } from 'src/app/services/domain.service';

@Component({
  selector: 'app-main-menu',
  templateUrl: './main-menu.component.html',
  styleUrls: ['./main-menu.component.css']
})
export class MainMenuComponent implements OnInit {

  show:boolean = true;

  constructor(
    public rootsvc : DomainService
  ) { }
  

  ngOnInit(): void {
    this.rootsvc.pivotReady.subscribe(data=>{
      let len:number=0;
      this.rootsvc.progress.subscribe(d=>len=d.length);
      if(data==len-1){
        this.show=false;
      }
    });
  }

}
