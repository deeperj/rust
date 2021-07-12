import { Progression } from "../models/Progression"
import { Progress } from "../models/ui/Progress"

export class AddProgress {
    static readonly type = '[Progression] Add'

    constructor(public payload: Progress) {}
}

export class RemoveProgress {
    static readonly type = '[Progression] Remove'

    constructor(public payload: number) {}
}

export class UpdateSummative {
    static readonly type = '[Progression] UpdateSummative'

    constructor(public payload: Progression[]) {}
}

export class UpdateFormative {
    static readonly type = '[Progression] UpdateFormmative'

    constructor(public payload: Progression[]) {}
}
