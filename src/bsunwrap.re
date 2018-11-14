module Date = {
  type t;

  [@bs.new]
  external make: ([@bs.unwrap] [ | `Value(float) | `String(string)]) => t =
    "Date";
};

let date1 = Date.make(`Value(107849354.));
let date2 = Date.make(`String("1995-12-17T03:24:00"));