[@bs.module "../util/utilities"] external bottomDistance : Dom.event => int = "distanceFromBottom";

[@bs.val] external setTimeout : (unit => unit, int) => float = "setTimeout";