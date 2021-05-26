import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SumAssessmentComponent } from './sum-assessment.component';

describe('SumAssessmentComponent', () => {
  let component: SumAssessmentComponent;
  let fixture: ComponentFixture<SumAssessmentComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SumAssessmentComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SumAssessmentComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
