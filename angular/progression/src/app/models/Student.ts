import { Group } from './Group';
import { Progression } from './Progression';

export interface Student {
    id: number;
    groupId: number;
    uniCode: string;
    sgCode: string|null;
    lastName: string;
    otherNames: string;
    startDate: Date|string;
    
    group: Group;

    progressions: Progression[];
}
