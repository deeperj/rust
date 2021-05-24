import { TestBed } from '@angular/core/testing';

import { DomainService } from './domain.service';

describe('AttendanceService', () => {
  let service: DomainService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(DomainService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
