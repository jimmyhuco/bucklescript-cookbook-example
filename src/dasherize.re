let code = {|
  let borderLeftColor = "borderLeftColor";
  let borderRightColor = "borderRightColor";
|};

let matchLetter = (letter, _, _) => "-" ++ Js.String.toLowerCase(letter);

let matchLiterals = (_, p1, _, _) => {
  let t = Js.String.unsafeReplaceBy0([%re "/[A-Z]/g"], matchLetter, p1);
  {j|"$t"|j};
};

code
|> Js.String.unsafeReplaceBy1([%re "/\"([^\"]*)\"/g"], matchLiterals)
|> Js.log;