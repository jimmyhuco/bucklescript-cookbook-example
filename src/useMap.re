let () = {
  module StringMap =
    Map.Make({
      type t = string;
      let compare = compare;
    });

  /* Alternatively, for modules which already conform to this signature */
  /* module StringMap = Map.Make(String); */

  let painIndexMap =
    StringMap.(
      empty
      |> add("western paper wasp", 1.0)
      |> add("yellowjacket", 2.0)
      |> add("honey bee", 2.0)
      |> add("red paper wasp", 3.0)
      |> add("tarantula hawk", 4.0)
      |> add("bullet ant", 4.0)
    );

  painIndexMap
  |> StringMap.add("bumble bee", 2.0)
  |> StringMap.iter((k, v) => Js.log({j|key:$k, val:$v|j}));
};