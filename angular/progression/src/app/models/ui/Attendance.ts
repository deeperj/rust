import { Rpag } from '../enums';
import { GroupModule } from '../GroupModule';
import { Module } from '../Module';
import { Progression } from '../Progression';


export interface Attendance {
  groupModule: GroupModule;
  groupNumber: number;
  moduleName: string;
  students: (Progression & AttendanceRecord)[];
}
export interface AttendanceRecord{
  attendanceScore: string|null;
  rpag: Rpag |null;
  attendance: Progression[];
  // attendance: {[k: string]: any}|null;
}
