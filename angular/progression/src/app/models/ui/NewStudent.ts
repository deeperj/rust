import { DomainService } from "src/app/services/domain.service";
import { RPAGType } from "../enums";
import { Progression } from "../Progression";

export interface NewStudent {
    groupId: number;
    uniCode: string;
    sgCode: string|null;
    lastName: string;
    otherNames: string;
}

export interface ProgressUpdate{
    studIdx: number;
    gmid: number;
    progressions: Progression[];
    rpagType: RPAGType;
    doRpag: boolean;
    // rootsvc:DomainService;
}
