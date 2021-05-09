import { GroupModule } from '../GroupModule';
import { Progression } from '../Progression';


export interface Attendance {
  groupModuleId: number;
  groupNumber: number;
  moduleName: string;
  students: Progression[];
}

export interface AttendanceReport {
  groupModule: GroupModule;
  dates: Date[] ;
  moduleName: string;
  students: Progression[];
}

export interface StudentRecord{
  SN: number;
  StudentID: string;
  LastName: string;
  OtherNames: string;
}
