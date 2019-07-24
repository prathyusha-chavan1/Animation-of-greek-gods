import React from 'react';
import { Link } from 'react-router-dom'



// function loaddata(props)
// {
//     <a href=props.data.f2f_url />
// }
function Recipe(props) {
  return (
    
    <div className="col-md-4" style={{marginBottom:"2rem"}}>
      <div className="recipes__box">
      
          
     <img  className="recipes__box-img" src={props.data.image_url} alt=" not available">
     </img>
     <div className="recipes__text">
     <h5 className="recipes__title"> {props.data.title}</h5> 
      <p className="recipes__subtitle">Publisher:<span>{props.data.publisher}</span></p>
      </div>
     {/* <button type="button">More details</button> */}
     <button className="recipe_buttons">
     <Link  to={`/recipe/${props.data.recipe_id}`} >
     View More
     </Link>
     </button>
    
     {/* <h3>Ingredients</h3>
     <ol>
       <li>12 whole New Potatoes (or Other Small Round Potatoes)</li>
       <li>3 Tablespoons Olive Oil</li>
       <li>Kosher Salt To Taste</li>
       <li>Black Pepper To Taste</li>
       <li>Rosemary (or Other Herbs Of Choice) To Taste</li>
     </ol>
     <p>click here for the recepi:</p>
     <a href="https://thepioneerwoman.com/cooking/crash-hot-potatoes/">Crash Hot Potatoes Recipe</a> */}
     </div>
    </div>

  );
}

export default Recipe;