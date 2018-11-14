let () =
  for (a in 1 to 10) {
    for (b in 1 to 10) {
      let product = a * b;
      Js.log({j|$a times $b is $product|j});
    };
  };