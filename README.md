# Society Simulation


Draft 0

Courtney Downs, Rayfuzu Software

Idea Conceived: 4/14/21

# Overview
The purpose of this simulation is to figure out how to build a utopian society. This society should be able to sustain a balanced state without conflict or disease for multiple generations once it has reached the status of a Utopia. Also, if a random societal interruption (S.I.) is added to the simulation it must be able to quickly (within weeks) regain a state of complete balance. The program will be easily configurable to model a society with specified environmental characteristics and common personality traits of individuals. 

A secondary objective for this project is to observe how a society evolves over multiple generations and log how they develop unique traits and norms based on random historic events. 



*Note:
- The ratios and values of this simulation do not have to be correct at first, just the architecture. Research will be needed to get correct values and behavior.
- EPA (Environmental Protection Agency) has databases and research articles that you can use to make this simulation more accurate.*



Modes

- Interactive
  - Adjust or view individual people and historic events at run time to try and create a utopia.
- Autopilot
  - Set a number of years to run and view data in post from the logs and database.

Level 0

The level 0 diagram below shows the highest possible level of the overall simulation. The main two components are the **Controller** and the **Sim Object**. The controller feeds commands into the sim object and the sim object executes internal processes and stores all results.

![](/Images/level0-dfd.drawio.png)

Level 1

The level 1 diagram below shows a slightly more low level design compared to level 0. You&#39;ll notice next to the Controller there are now two external entities, the **User** and the **Configuration File.** The purpose for this is to show that the sim can support both interactive and passive modes. Inside of the controller you&#39;ll see all of the current commands that it can send to the sim object.

Inside of the Sim Object you&#39;ll notice the **World Builder.** This object will be able to read a **WorldConfig.json** file and create the listed objects with their desired properties and pass those objects to the **Sim Manager.**

![](/Images/level1-dfd.drawio.png)

Level 2

In the level 2 diagram below you&#39;ll notice the following new items: **Environment Manager** , **Data Analyzer** ,and the **State Injector.**

1. Environment Manager
  1. This object&#39;s main goal is to manage the assignment of **Environmental Conditions** and **Environmental Decisions** to the correct Environments. However, since this manager has direct access to all populations of each environment then it will also be incharge of handling the **Relocation of Persons** based on their schedules.
2. Data Analyzer
  1. This object&#39;s main goal is to analyze the state of the simulation&#39;s operations and make sure that everything is running as expected as far as each component is giving expected outputs. But also the Data Analyzer will be responsible for checking every frame for **Historical Events**.
3. State Injector
  1. The objective of this object is to be able to add random **Societal Interruptions**. This will most likely be done by modifying the **WorldConfig.json** with values associated with the given Societal Interruption. (pandemic, war, riots, etc..)

![](/Images/level2-dfd.drawio.png)

1.
# CSCIs (Computer Software Configuration Items)

Listed below are all of the computer software configuration items that will be required for this simulation:

1. Person
2. Historic Event
3. Schedule
4. Decision Tree
5. Environment
6. Societal Interruption

1.
# Person

#

A person object is a representation of an individual that can interact with other persons in different environments to achieve a task from their schedule by making decisions. All interactions and decisions will be logged for each person and the effect will be calculated.

Type:

- Employer/Employee (Work)
- Teacher/Student (School)
- Adult/Child (Home)

The most important aspects of this simulation that will need to be properly captured is how to model and adjust **&quot;Work/Life balance&quot;.** This will impact how effective individuals are on a day to day in their jobs and in their lives in general. Which will also affect how effective they are making their respective companies and businesses that they work for which will ultimately affect the country and world as a whole.

How to measure work life balance ?

1. Days since made significant progress on personal goals (DSSPG)
  1. If DSSPG ++ then Stress ++
  2. If DSSPG - - then Stress - -
2. Days since made significant progress on work tasks (DSSPW)
  1. If DSSPW ++ then Stress ++ Productivity - -
  2. If DSSPW - - then Stress - - Productivity ++

Properties:

1. ID
2. Daily Schedule
3. Happy %
4. Hours Since Slept
5. Hours Since Ate
6. Is Employed
7. Potential Fields
  1. Life decision tree
  2. Literacy
    1. Level of education { high school, bachelors, masters, phd}
  3. Annual Salary
  4. Ethnicity or Ethnicities and their percentages
    1. 20% African American. 20%Asian, 15%Indian
  5. Gender
  6. Age
    1. Double (updated daily)
  7. Health
    1. Healthy, Common Cold, Specific Virus, Specific Terminal Illness
  8. Social Network Graph
    1. Friends and family


_ **QUESTION** __: How are births and deaths handled? Do they need to be captured?_

_If so, how and if not why not?_

1.
# Historic Event

A historic event is a major event that can occur automatically once all environmental factors and social traits have met given thresholds.

**Radical Innovation**

My stretch goal for historic events is to find a way to have the system automatically generate new kinds of historic events based on how the society evolves. That way historic events won&#39;t be limited to the finite number that I program into the simulation. Find out how to generalize the person&#39;s properties also because they are currently directly related to what is needed for measuring the threshold of current historic events.

Initial Historic Events:

1. First World Country
2. Social Equality
3. High Quality of Health

Thresholds to measure:

**First\_World\_Country** {

GDP

GNP

Life\_Expectancy

Literacy\_Rate

Human\_Development\_Index

}

How to calculate GDP?

[https://www.britannica.com/topic/gross-domestic-product](https://www.britannica.com/topic/gross-domestic-product)

**Social\_Equality**

{

Time Since Last Race Riot: 10years +,

AverageEthnicDiversityInFriendGroup: 3+ (3+ ethnicities)

AverageEthnicDiversityInOffspring: 2+ (2+ ethnicities)

Average Ethnic Income Equality: \&gt; 85%

}

**High\_Quality\_of\_Health**

{

Life\_Expectancy: 100 years

Less than 1% of population dies of sickness or disease annually: Boolean

95% of Diseases are cured or managable: Boolean

}

_ **IMPORTANT** __: Develop a simple ICD language for translating H.E thresholds_

_from world config JSON to C++ conditionals._

1.
# Schedule

A schedule is an object that will be automatically generated for each person and it will consist of multiple tasks with times and daily frequencies along with location that the task must take place.

1. Relocation
  1. These tasks will physically relocate the person to a new environment which will introduce them to a different tree of decisions and a different group of people to interact with. The schedule will start out as a basic list of relations such as: go home, go to school, and go to work (different times for each day to reflect class workload.)

Relocation Task Example:

{

Days: &quot;MWF&quot;

Time: &quot;1:00pm&quot;

Location: &quot;School&quot;

Task Name: &quot;Math Class&quot;

}

1.
# Decision Tree

A decision tree is an object that will be automatically generated for each unique type of environment. Once a person enters that environment then they will execute tasks based on decisions made from the decision tree. Each decision made will affect the mood of the person that made it in some predetermined way. Also, each person will have a life decision tree that grows and logs each major decision that they make in their life.

![Shape1](RackMultipart20220120-4-1b23n82_html_850d2d01b37ef6a1.gif)

List of all possible decisions with their choices, mood outcomes, effects, and which choices could possibly be child nodes of parent choices.

Mood ranges:

Mood of the individual determines how they make decisions. (initialized daily with random values). These ranges are updated by environmental conditions and decisions and the mood/state of the person determines their level of productivity at school/work.

Data Files:

- WorkDecisions.json
  - Contains all decisions related to productivity and innovation.
    - Examples:
      - Ate breakfast ?
      - Eat lunch ?
      - Hours Slept ?
      - Idle social interactions ? (distracted by co-workers)
- HomeDecisions.json
- SchoolDecisions.json
- ScheduleTasks.json

Decision Tree in JSON:

A?, A Ans1, A Ans2

A Ans1, B?

B?, B Ans1, B Ans2

A Ans2, C?

C?, C Ans1, C Ans2

Each environment&#39;s decision tree will be auto generated on sim start. Built with random selections from XDecision.json file.

Example Schedule and decision tree:

{task:&quot;School&quot;, time: 1p}

{task:&quot;Work&quot;, time: 5p}

{task:&quot;Home&quot;, time: 11p}

…

This example schedule will have the person at school for 4h. In that time they will evaluate and make decisions from that school environment&#39;s decision tree and complete the tree every hour and their mood and properties will be adjusted accordingly.

1. Social Interaction
  1. These interactions will cause the interacting parties to have their properties (i.e mood, literacy, decisions, etc. ) change based on each other&#39;s properties. (Develop the algorithm for this, it can be very simple for a crawl phase)

Social Interaction Task Example:

{

Person: \&lt;PersonID\&gt;

Task: &quot;Do something&quot;

Duration: 1h

}

1.
# Environment

An environment is a **home** , **school** , or **work** location that a person can be in at any given time during the simulation.

Environment specific properties:

- Work Environment (Business / Company)
  - Annual Sales $$$ (Contributes to GDP of country)
    - Goes up when workers are more productive and innovative (How to measure this well enough?)

Environmental Traits:

1. Toxic %
2. Innovative %
3. Healthy %
4. Renewable Energy %

Social Environmental Actions:

1. addFriend()
2. removeFriend()
3. addAssociate()
4. removeAssociate()

A Person is more likely to adopt traits of friends than associates.

1.
# Societal Interruptions

A societal interruption (S.I) is an event that can randomly occur to add unexpected changes to the simulation. Each S.I has specific **Environmental Conditions** associated with it that will determine how individuals in specific environments are affected by the given S.I.

Examples:

1. **Pandemic**
  1. Conditions
    1. &quot;percentageOfBusinessesGoingRemote&quot;: 0.80,
    2. &quot;percentageOfPopulationInfected&quot;: 0.67,
    3. &quot;lethalityRateOfVirus&quot;: 0.45
2. **Civil War**
  1. Conditions
    1.
3. **Recession**
  1. Conditions
    1. &quot;UnemploymentPercentage&quot;: 0.50,
    2. &quot;AverageStress&quot;: 0.80,
    3. &quot;AverageBusinessPerformance&quot;: 0.60
    4. &quot;AverageSalaryOffset&quot;: -0.30

These conditions are applied to the simulation through the WorldConfig.json file. After a specific S.I has been set for the simulation run, the **Adaptation Engine** will be responsible for making the population choose decisions to counter the effects of the S.I and eventually become immune to it. (If the same S.I returns the population will know how to handle it, i.e. A world state is logged to a database with successful responses to S.Is).

1.
# Main Flow

![](/Images/main_flow.drawio.png)

The main flow of this simulation will be decided by the current Societal Interruption (S.I) that is applied to the world state in the World Config file. That S.I will have associated conditions that will be applied to specific environments and a percentage or all of the population. These conditions will affect how those individuals make decisions in their environment. All of those decisions should eventually lead to a **corresponding Historic Event (H.E).** As the decisions are made they are logged to the database for **post analysis.**

_For the society to achieve a state of Utopia, they have to experience multiple S.I&#39;s to learn from them and achieve all three H.E&#39;s._

- S.I to H.E mapping

1. Recession ⇔ First World Country
2. War ⇔ Social Equality
3. Pandemic ⇔ High Quality of Health

1. After many recessions, the economy will evolve enough to improve GDP/GNP/ etc.
2. After multiple wars, societies will develop a framework to better communicate and understand each other, which will lead to greater compassion and less conflict.
3. After multiple pandemics, the society will evolve health care systems and sanitation standards and norms to lead to higher quality of health.

Process for updating the **Global World State** variables.

- Example:

Constantly add to businesses earnings and combine all business profits

to calculate GDP for &quot;First World Country&quot; thresholds.

1.
# User Interface Mocks

- **Interactive mode** : When you want to change values in the simulation at run time, what mechanisms do you need to design to make that happen?

1.
# System Logs &amp; Database

#

- Will use **MongoDB** (To get M experience from MERN)
- Come up with a mongo schema or find standards
- Study database design and what makes Mongo special compared to the other database options available today.

Society Simulation Documentation