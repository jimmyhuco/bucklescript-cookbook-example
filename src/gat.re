module Date = {
  type t;

  type makeArg('a) =
    | Value: makeArg(float)
    | String: makeArg(string);

  [@bs.new] external make: ([@bs.ignore] makeArg('a), 'a) => t = "Date";
};

let date1 = Date.make(Value, 107849354.);
let date2 = Date.make(String, "1995-12-17T03:24:00");