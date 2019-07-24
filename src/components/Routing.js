import React from 'react';

import { BrowserRouter,Switch,Route } from "react-router-dom";
//import { BrowserRouter } from 'react-router-dom/cjs/react-router-dom';
import RecipeDetails from './RecipeDetails';
import App from './../App';
function Routing(props) {
  return (

    <BrowserRouter>
    <Switch>
        <Route exact path="/"
        component={App}
        />
        <Route exact path="/recipe/:id"
        component={RecipeDetails}
        />

    </Switch>
    </BrowserRouter>
    
  )
}
export default Routing;