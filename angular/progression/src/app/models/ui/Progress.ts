import { Rpag } from '../enums';
import { GroupModule } from '../GroupModule';
import { Module } from '../Module';
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
  attendance: Progression[];
  summatives: Progression[];
  attendanceCount: number;
  // attendance: {[k: string]: any}|null;
}
