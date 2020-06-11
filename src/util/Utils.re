[@bs.module "../util/utilities"] external bottomDistance : Dom.event => int = "distanceFromBottom";

[@bs.module "../util/utilities"] external scroller: Dom.event => bool = "scroller";

[@bs.val] external setTimeout : (unit => unit, int) => float = "setTimeout";