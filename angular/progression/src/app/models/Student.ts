import { Group } from './Group';
import { Progression } from './Progression';

export interface Student {
    ID: number;
    GroupID: number;
    UniCode: string;
    SGCode: string;
    LastName: string;
    OtherNames: string;

    Group: Group;

    Progressions: Progression[];
}
