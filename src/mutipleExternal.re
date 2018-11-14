module Date = {
  type t;

  [@bs.new] external fromValue: float => t = "Date";
  [@bs.new] external fromString: string => t = "Date";
};

let date1 = Date.fromValue(107849354.);
let date2 = Date.fromString("1995-12-17T03:24:00");