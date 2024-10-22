open Css;

let containerStyle =
  merge([
    style([
      display(flexBox),
      paddingLeft(`percent(15.)),
      paddingRight(`percent(15.)),
      flexDirection(column),
      height(`percent(100.))
    ]),
    "container"
  ]);


[@react.component]
let make = (~children: React.element) =>
  <>
    <Navbar />
    <div className=containerStyle>
      children
    </div>
  </>