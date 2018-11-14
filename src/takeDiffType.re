module Arg = {
  type t;

  external int: int => t = "%identity";
  external string: string => t = "%identity";
};

[@bs.val] [@bs.splice]
external executeCommand: (string, array(Arg.t)) => unit = "";

let () = executeCommand("copy", Arg.([|string("text/html"), int(2)|]));