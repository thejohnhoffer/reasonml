let toRnaFromChar =
  fun
  | 'A' => 'U'
  | 'C' => 'G'
  | 'G' => 'C'
  | 'T' => 'A'
  |  _  => 'x';

let toRnaFromString = String.map(toRnaFromChar);
let hasNoLower = str => String.uppercase(str) == str;
let validDna = str => str |> toRnaFromString |> hasNoLower;
let toRna = str => if (validDna(str)) toRnaFromString(str) else "Invalid input";

/* Tests pass with `let validRna = validDna`, but that's incorrect*/
let validRna = str => str |> String.map({
  fun
  | 'A' | 'C' | 'G' | 'U' => ' '
  |  _  => 'x';
}) |> hasNoLower;
