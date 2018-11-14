type line = {
  start: point,
  end_: point,
  thickness: option(int),
}
and point = {
  x: float,
  y: float,
};

module Encode = {
  let point = r => {
    open! Json.Encode;
    object_([("x", float(r.x)), ("y", float(r.y))]);
  };
  let line = r =>
    Json.Encode.(
      object_([
        ("start", point(r.start)),
        ("end", point(r.end_)),
        (
          "thickness",
          switch (r.thickness) {
          | Some(x) => int(x)
          | None => null
          },
        ),
      ])
    );
};

let data = {
  start: {
    x: 1.1,
    y: (-0.4),
  },
  end_: {
    x: 5.3,
    y: 3.8,
  },
  thickness: Some(2),
};

let json = data |> Encode.line |> Js.Json.stringify;
let () = Js.log(json);