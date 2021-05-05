import { Group } from './Group';


export interface Batch {
  batchId: number;
  batchCode: string;
  term1StartDate: Date | string;
  term2StartDate: Date | string;
  midTerm1Date: Date | string;
  endTerm1Date: Date | string;
  midTerm2Date: Date | string;
  endTerm2Date: Date | string;
  isActive: boolean;

  groups: Group[];
}

