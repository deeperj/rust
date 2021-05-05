import { Group } from './Group';
import { Progression } from './Progression';

export interface Student {
    id: number;
    groupId: number;
    uniCode: string;
    sgCode: string;
    lastName: string;
    otherNames: string;

    group: Group;

    progressions: Progression[];
}
