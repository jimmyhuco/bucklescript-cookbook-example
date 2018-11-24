open Belt;

module StrHash =
  Id.MakeHashable({
    type t = string;
    let hash = String.length;
    let eq = (==);
  });

let painIndexMap = HashMap.make(~hintSize=10, ~id=(module StrHash));

let () = {
  open HashMap;
  set(painIndexMap, "western paper wasp", 1.0);
  set(painIndexMap, "yellowjacket", 2.0);
  set(painIndexMap, "honey bee", 2.0);
  set(painIndexMap, "red paper wasp", 3.0);
  set(painIndexMap, "tarantula hawk", 4.0);
  set(painIndexMap, "bullet ant", 4.0);
};

let () = HashMap.set(painIndexMap, "bumble bee", 2.0);

let () =
  HashMap.forEach(painIndexMap, (k, v) => Js.log({j|key:$k, val:$v|j}));