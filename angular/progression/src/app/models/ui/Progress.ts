import { Rpag } from '../enums';
import { GroupModule } from '../GroupModule';
import { Module } from '../Module';
import { Progression } from '../Progression';


export interface Progress {
  groupModule: GroupModule;
  groupNumber: number;
  moduleName: string;
  progressRecords: (Progression & ProgressRecord)[];
}
export interface ProgressRecord{
  score: string|null;
  rpag: Rpag |null;
  progress: Progression[];
  attendanceCount: number;
  // attendance: {[k: string]: any}|null;
}
