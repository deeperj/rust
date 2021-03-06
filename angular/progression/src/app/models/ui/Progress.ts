import { Rpag } from '../enums';
import { GroupModule } from '../GroupModule';
import { Progression } from '../Progression';


export interface Progress {
  groupModule: GroupModule;
  groupNumber: number;
  moduleName: string;
  studentProgress: (Progression & ProgressRecord)[];
}
export interface ProgressRecord{
  attendanceScore: string|null;
  attendanceRpag: Rpag |null;
  formativeScore: string|null;
  summativeScore: string|null;
  summaryScore: string|null;
  summativeRpag: Rpag |null;
  summaryRpag: Rpag |null;
  attendance: Progression[];
  summatives: Progression[];
  formatives: Progression[];
  attendanceCount: number;
  // attendance: {[k: string]: any}|null;
}

export interface ModEmailStatus
{
    password: string;
    sendToday: boolean
    gMID:number
}

