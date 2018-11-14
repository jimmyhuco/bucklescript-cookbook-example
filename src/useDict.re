let painIndexMap =
  Js.Dict.fromList([
    ("western paper wasp", 1.0),
    ("yellowjacket", 2.0),
    ("honey bee", 2.0),
    ("red paper wasp", 3.0),
    ("tarantula hawk", 4.0),
    ("bullet ant", 4.0),
  ]);

let () = Js.Dict.set(painIndexMap, "bumble bee", 2.0);

let () =
  painIndexMap
  |> Js.Dict.entries
  |> Js.Array.forEach(((k, v)) => Js.log({j|key:$k, val:$v|j}));