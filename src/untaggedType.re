/* Bind to the function, using Js.Json.t to capture the untagged union */
[@bs.val] external getRandomlyTypedValue: unit => Js.Json.t = "";

/* Override the binding with a function that converts the return value */
let getRandomlyTypedValue = () =>
  switch (Js.Json.classify(getRandomlyTypedValue())) {
  | Js.Json.JSONNumber(n) => `Float(n)
  | Js.Json.JSONString(s) => `String(s)
  | _ => failwith("unreachable")
  };

/* The function can now be used safely and idiomatically */
let () =
  switch (getRandomlyTypedValue()) {
  | `Float(n) => Js.log2("Float: ", n)
  | `String(s) => Js.log2("String: ", s)
  };