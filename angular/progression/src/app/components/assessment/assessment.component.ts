import { Component, OnInit } from '@angular/core';
import { DomainService } from 'src/app/services/domain.service';

@Component({
  selector: 'app-assessment',
  templateUrl: './assessment.component.html',
  styleUrls: ['./assessment.component.css']
})
export class AssessmentComponent implements OnInit {

  constructor( 
    public rootsvc : DomainService) 
    { 
    }

  ngOnInit(): void {
  }

}
