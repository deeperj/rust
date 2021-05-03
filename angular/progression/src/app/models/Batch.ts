import { Group } from './Group';


export interface Batch {
  BatchID: number;
  BatchCode: string;
  Term1StartDate: Date | string;
  Term2StartDate: Date | string;
  MidTerm1Date: Date | string;
  EndTerm1Date: Date | string;
  MidTerm2Date: Date | string;
  EndTerm2Date: Date | string;
  IsActive: boolean;

  Groups: Group[];
}

