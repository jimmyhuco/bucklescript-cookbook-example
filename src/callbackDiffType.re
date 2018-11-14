type doneFn = option(string) => unit;
[@bs.val]
external withAsyncCallback: ((Js.Json.t => unit) => unit) => unit = "";
let withAsyncCallback: (doneFn => unit) => unit =
  f =>
    withAsyncCallback(done_ =>
      f(
        fun
        | Some(value) => value |> Js.Json.string |> done_
        | None => false |> Js.Json.boolean |> done_,
      )
    );