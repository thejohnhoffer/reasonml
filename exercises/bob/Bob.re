type tone = Talking | Shouting;

let bobParse = s => {
  switch (String.(get(s, length(s) - 1), s == lowercase(s), s == uppercase(s))) {
    | exception Invalid_argument(_) => None
    | (c, false, true) => Some((Shouting, c))
    | (c, _, _) => Some((Talking, c))
  };
};

let bobSpeak =
  fun
  | None => "Fine. Be that way!"
  | Some((Shouting, '?')) => "Calm down, I know what I'm doing!"
  | Some((Shouting, _)) => "Whoa, chill out!"
  | Some((Talking, '?')) => "Sure."
  | Some((Talking, _)) => "Whatever.";

let hey = saying => {
  saying
    |> String.trim
    |> bobParse
    |> bobSpeak;
};
