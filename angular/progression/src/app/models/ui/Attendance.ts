import { Progression } from '../Progression';


export interface Attendance {
  groupModuleId: number;
  groupNumber: number;
  moduleName: string;
  students: Progression[];
}
