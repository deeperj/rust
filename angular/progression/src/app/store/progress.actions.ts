import { ProgressUpdate } from "../models/ui/NewStudent"
import { Progress } from "../models/ui/Progress"

export class AddProgress {
    static readonly type = '[Progression] Add'
    constructor(public payload: Progress) {}
}

export class UpdateProgress {
    static readonly type = '[Progression] UpdateProgress'
    constructor(public payload: ProgressUpdate) {}
}


