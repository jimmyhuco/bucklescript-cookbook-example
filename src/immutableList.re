let painIndexMap = [
  ("western paper wasp", 1.0),
  ("yellowjacket", 2.0),
  ("honey bee", 2.0),
  ("red paper wasp", 3.0),
  ("tarantula hawk", 4.0),
  ("bullet ant", 4.0),
];

let addOrReplace = ((k, v), l) => {
  let l' = List.remove_assoc(k, l);
  [(k, v), ...l'];
};

let () =
  painIndexMap
  |> addOrReplace(("bumble bee", 2.0))
  |> List.iter(((k, v)) => Js.log({j|key:$k, val:$v|j}));