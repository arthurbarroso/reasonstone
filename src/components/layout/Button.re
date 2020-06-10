open Css;

let textColor = (isHovering: bool) => isHovering ? hex("fcba03") : hex("fff");

type state = {isHovering: bool};
type action =
  | ToggleHover;


let centerButtonStyle = (isHovering: bool) => {
  let usedColor = textColor(isHovering);

  merge([
    style([
      alignSelf(center),
      background(hex("333")),
      color(usedColor),
      borderRadius(px(4)),
      marginTop(`percent(4.)),
      marginBottom(`percent(20.)),
      borderWidth(px(0)),
      height(px(48)),
      padding(px(8)),
      width(px(240))
    ]),
    "center-button"
  ]);
};



[@react.component]
let make = (~text: string, ~onClick) => {
  let (state, dispatch) =
  React.useReducer(
    (state, action) =>
      switch (action) {
        | ToggleHover => {isHovering: !state.isHovering}
      },
    {isHovering: false},
  );
  <button
    onMouseOver={_event => dispatch(ToggleHover)}
    onMouseOut={_event => dispatch(ToggleHover)} 
    className=centerButtonStyle(state.isHovering)
    onClick={_ => onClick()}>{ReasonReact.string(text)}
  </button>
}