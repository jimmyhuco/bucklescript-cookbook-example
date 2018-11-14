open Belt
let painIndexMap = HashMap.String.make ~hintSize:10
let () =
  let open HashMap.String in
    set painIndexMap "western paper wasp" 1.0;
    set painIndexMap "yellowjacket" 2.0;
    set painIndexMap "honey bee" 2.0;
    set painIndexMap "red paper wasp" 3.0;
    set painIndexMap "tarantula hawk" 4.0;
    set painIndexMap "bullet ant" 4.0

let () =
  HashMap.String.set painIndexMap "bumble bee" 2.0

let () =
  painIndexMap |. HashMap.String.forEach (fun k  -> fun v  -> Js.log {j|key:$k, val:$v|j})