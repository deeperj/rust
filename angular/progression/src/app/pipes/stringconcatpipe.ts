import { Pipe, PipeTransform } from '@angular/core';
/*
 * Raise the value exponentially
 * Takes an exponent argument that defaults to 1.
 * Usage:
 *   value | exponentialStrength:exponent
 * Example:
 *   {{ 2 | exponentialStrength:10 }}
 *   formats to: 1024
*/
@Pipe({name: 'concat'})//NOT CALLED YET
export class StringConcatPipe implements PipeTransform {
  transform(value: string, other?: string): string {
    return value.concat(' '+other);
  }
}